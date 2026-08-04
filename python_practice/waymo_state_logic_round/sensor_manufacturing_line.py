# Autonomous Sensor Manufacturing Line
# You're monitoring a sensor assembly line. 
# Each sensor unit goes through manufacturing stages before being cleared for vehicle installation.
# 
# States:
# RAW → ASSEMBLED → TESTED → CALIBRATED → APPROVED → INSTALLED 
# 
# Rules:
# Each stage must happen in order — no skipping
# A sensor can only receive quality_check while TESTED
# If a sensor gets 2 consecutive failed quality_check events it moves to SCRAPPED
# A SCRAPPED sensor cannot receive any events
# A sensor can only be recalled from INSTALLED — which sends it back to TESTED
# A recalled sensor must pass quality_check before it can be approved again


# EVENTS :  assemble, test, calibrate, approve, install, recall
# STATES: RAW, ASSEMBLE, TESTED, CALIBRATED, APPROVED, INSTALLED, SCRAPPED(cannot receive more events)

events = [
    ("sensor_001", "assemble"),
    ("sensor_001", "test"),
    ("sensor_001", "quality_check", "pass"),
    ("sensor_001", "calibrate"),
    ("sensor_001", "approve"),
    ("sensor_001", "install"),
    ("sensor_001", "recall"),                    # back to TESTED
    ("sensor_001", "quality_check", "fail"),
    ("sensor_001", "quality_check", "fail"),     # SCRAPPED
    ("sensor_001", "quality_check", "pass"),     # violation - SCRAPPED
    ("sensor_002", "test"),                      # violation - skipped assemble
    ("sensor_002", "assemble"),
    ("sensor_002", "test"),
    ("sensor_002", "approve"),                   # violation - not tested properly
    ("sensor_002", "quality_check", "pass"),
    ("sensor_003", "install"),                   # violation - not approved
]


from enum import Enum, auto

class SensorState(Enum):
    RAW = auto()
    ASSEMBLED = auto()
    TESTED = auto()
    CALIBRATED = auto()
    APPROVED = auto()
    INSTALLED = auto()
    SCRAPPED  = auto()

EVENTS_TO_STATES = {
    "assemble" : SensorState.ASSEMBLED,
    "test" : SensorState.TESTED,
    "calibrate" : SensorState.CALIBRATED,
    "approve" : SensorState.APPROVED,
    "install" : SensorState.INSTALLED,
    "recall" : SensorState.TESTED
}

VALID_TRANSITIONS = {
    SensorState.RAW : SensorState.ASSEMBLED,
    SensorState.ASSEMBLED : SensorState.TESTED,
    SensorState.TESTED : SensorState.CALIBRATED,
    SensorState.CALIBRATED : SensorState.APPROVED,
    SensorState.APPROVED : SensorState.INSTALLED,
    SensorState.INSTALLED : SensorState.TESTED,
}

class SensorRecord:
    def __init__(self):
        self.state = SensorState.RAW
        self.quality_check_count = 0

class SensorManufacturingPipeline:
    def __init__(self):
        self.sensors : dict [str, SensorRecord] = {}
        
    def process_event(self, sensor_id : str, event: str, status: str) :

        # 1. frame the sensors in sensor record
        if sensor_id not in self.sensors:
            self.sensors[sensor_id] = SensorRecord()
        curr_record = self.sensors[sensor_id] 

        if curr_record.state == SensorState.SCRAPPED:
            print(f"The current {sensor_id} is moved to SCRAPPED. Cannot take more events")
            return

        if event == "recall":
            if curr_record.state == SensorState.INSTALLED:
                curr_record.state = SensorState.TESTED
                print(f"The current {sensor_id} is moved back to TESTED")
            else:
                print(f"VIOLATION: can only recall form installed")
            return
            
        if event == "quality_check":
            if curr_record.state == SensorState.TESTED:
                if status == "fail":
                    curr_record.quality_check_count += 1
                    if curr_record.quality_check_count >=2:
                        curr_record.state = SensorState.SCRAPPED
                        print(f"The current {sensor_id} is moved to {curr_record.state.name}")
                    else:
                        print(f"OKAY, Current {sensor_id} is FAILED")
                elif status == "pass":
                    curr_record.quality_check_count = 0
                    print(f"OKAY, Current {sensor_id} check is PASSED")
                return

        next_state = EVENTS_TO_STATES.get(event)
        expected_state = VALID_TRANSITIONS.get(curr_record.state)

        if expected_state != next_state:
            print(f"VIOLATION: The {sensor_id} is already in {curr_record.state.name}")
            return

        curr_record.state = next_state
        print(f"{sensor_id} is updated to {next_state.name}")    

Sensor_manufacturing_1 = SensorManufacturingPipeline()

for sensor_id, event, *other in events:
    if other:
        result = other[0]
    else:
        result = None
    Sensor_manufacturing_1.process_event(sensor_id, event, result)
                 



        



 