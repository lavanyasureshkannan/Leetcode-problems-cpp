# Autonomous Vehicle Sensor Calibration Pipeline
# You're managing a calibration pipeline for a fleet of vehicles. 
# Each vehicle must calibrate its sensors before deployment.
# 
# States:
# UNCALIBRATED → CALIBRATING → CALIBRATED → DEPLOYED
# Rules:

# A vehicle must be UNCALIBRATED before calibration_start
# A vehicle must be CALIBRATING before calibration_complete
# A vehicle must be CALIBRATED before deploy
# A vehicle can only send sensor_check while CALIBRATING
# If a vehicle sends 2 consecutive failed sensor_check events, flag it as CALIBRATION_FAILED and block further progress
# A CALIBRATION_FAILED vehicle can be reset — which sends it back to UNCALIBRATED
# A DEPLOYED vehicle cannot receive any events

events = [
    ("vehicle_A", "calibration_start"),
    ("vehicle_A", "sensor_check", "pass"),
    ("vehicle_A", "sensor_check", "fail"),
    ("vehicle_A", "sensor_check", "fail"),   # 2nd consecutive fail - CALIBRATION_FAILED
    ("vehicle_A", "calibration_complete"),   # violation - CALIBRATION_FAILED
    ("vehicle_A", "reset"),                  # back to UNCALIBRATED
    ("vehicle_A", "calibration_start"),
    ("vehicle_A", "sensor_check", "pass"),
    ("vehicle_A", "calibration_complete"),
    ("vehicle_A", "deploy"),
    ("vehicle_A", "calibration_start"),      # violation - already DEPLOYED
    ("vehicle_B", "calibration_complete"),   # violation - skipped start
    ("vehicle_B", "deploy"),                 # violation - not calibrated
]

from enum import Enum, auto

class VehicleStates(Enum):
    UNCALIBRATED = auto()
    CALIBRATING = auto()
    CALIBRATED = auto()
    DEPLOYED = auto()
    CALIBRATION_FAILED = auto()

EVENTS_TO_STATE = {
    "calibration_start" : VehicleStates.CALIBRATING,
    "calibration_complete" : VehicleStates.CALIBRATED,
    "deploy": VehicleStates.DEPLOYED,
    "reset" : VehicleStates.UNCALIBRATED
}

VALID_TRANSITIONS = {
    VehicleStates.UNCALIBRATED : VehicleStates.CALIBRATING,
    VehicleStates.CALIBRATING : VehicleStates.CALIBRATED,
    VehicleStates.CALIBRATED : VehicleStates.DEPLOYED,
    VehicleStates.CALIBRATION_FAILED :VehicleStates.UNCALIBRATED
}

class VehicleRecord:
    def __init__(self):
        self.state = VehicleStates.UNCALIBRATED
        self.calibration_fail_count = 0

class CalibrationPipelineCheck:
    def __init__(self):
        self.vehicles : dict[str, VehicleRecord] = {} 

    def process_Event(self, vehicle_ID : str, event : str, status : str):
        # 1. Check for the valid vehicle ID
        if vehicle_ID not in self.vehicles:
            self.vehicles[vehicle_ID] = VehicleRecord()
        curr_record = self.vehicles[vehicle_ID]

        if curr_record.state == VehicleStates.DEPLOYED:
            print(f"{vehicle_ID} VIOLATION: The vehicle is already DEPLOYED")
            return
        
        # 2. Check if the vehicle calibration is failed (2 consecutive checks)
        if event == "sensor_check":
            if curr_record.state == VehicleStates.CALIBRATING:  
                if status == "fail":
                    curr_record.calibration_fail_count += 1
                    if curr_record.calibration_fail_count >= 2:
                        curr_record.state = VehicleStates.CALIBRATION_FAILED
                        print(f"Calibration FAILED for the current  {vehicle_ID}")
                elif status == "pass":
                    curr_record.calibration_fail_count = 0
                    print(f"{vehicle_ID} OKAY, sensor check PASSED")
                return
        # 3. check the other states
        next_states = EVENTS_TO_STATE.get(event)
        expected_state = VALID_TRANSITIONS.get(curr_record.state)

        # 4. check for the validity of states
        if expected_state != next_states:
            print(f"VIOLATION: The {vehicle_ID} is already {curr_record.state.name}")
            return
        # 5. update the state
        curr_record.state = next_states
        print(f"{vehicle_ID} updated to {next_states.name}")         

Calibration_pipeline = CalibrationPipelineCheck()
for vehicles, event, *other in events:
    result = other[0] if other else None
    Calibration_pipeline.process_Event(vehicles, event, result)

            




            

            













