# Drone Fleet Monitoring System
# You're managing a fleet of delivery drones. Each drone goes through a flight lifecycle.


# States:
# GROUNDED → PRE_FLIGHT → IN_FLIGHT → LANDING → GROUNDED
# Rules:

# A drone must be GROUNDED before pre_flight_check
# A drone must be PRE_FLIGHT before takeoff
# A drone must be IN_FLIGHT before land
# A drone must be LANDING before touchdown
# A drone can only send telemetry while IN_FLIGHT
# If a drone sends 3 consecutive telemetry failures, 
#   flag it as EMERGENCY and block all events except emergency_land
# emergency_land moves an EMERGENCY drone to GROUNDED and resets the counter
# A drone that completes touchdown resets its telemetry counter


events = [
    ("drone_A", "pre_flight_check"),
    ("drone_A", "takeoff"),
    ("drone_A", "telemetry", "ok"),
    ("drone_A", "telemetry", "fail"),
    ("drone_A", "telemetry", "fail"),
    ("drone_A", "telemetry", "fail"),    # 3rd fail - EMERGENCY
    ("drone_A", "land"),                 # violation - EMERGENCY
    ("drone_A", "emergency_land"),       # back to GROUNDED
    ("drone_A", "pre_flight_check"),
    ("drone_A", "takeoff"),
    ("drone_A", "telemetry", "ok"),
    ("drone_A", "land"),
    ("drone_A", "touchdown"),
    ("drone_B", "takeoff"),              # violation - skipped pre_flight
    ("drone_B", "telemetry", "ok"),      # violation - not IN_FLIGHT
    ("drone_C", "pre_flight_check"),
    ("drone_C", "takeoff"),
    ("drone_C", "land"),
    ("drone_C", "pre_flight_check"),     # violation - not GROUNDED
]


from enum import Enum, auto

class DroneState(Enum):
    GROUNDED  = auto()
    PRE_FLIGHT = auto()
    IN_FLIGHT = auto()
    LANDING = auto()
    EMERGENCY = auto()

EVENTS_TO_STATES = {
    "pre_flight_check" : DroneState.PRE_FLIGHT,
    "takeoff": DroneState.IN_FLIGHT,
    "land": DroneState.LANDING,
    "emergency_land": DroneState.GROUNDED,
    "touchdown" : DroneState.GROUNDED
}

VALID_TRANSITIONS = {
    DroneState.GROUNDED : DroneState.PRE_FLIGHT,
    DroneState.PRE_FLIGHT : DroneState.IN_FLIGHT,
    DroneState.IN_FLIGHT : DroneState.LANDING,
    DroneState.LANDING :DroneState.GROUNDED,
    DroneState.EMERGENCY: DroneState.GROUNDED
}


class DroneRecord:
    def __init__ (self) :
        self.state = DroneState.GROUNDED
        self.telementry_count = 0

class DroneFleetMonitor:
    def __init__(self):
        self.drones : dict [str, DroneRecord] = {}
    def process_event(self, drone_id:str, event:str, status:str):

        if drone_id not in self.drones:
            self.drones[drone_id] = DroneRecord()
        curr_record = self.drones[drone_id]

        if curr_record.state == DroneState.EMERGENCY and event != "emergency_land":
            print(f"{drone_id} VIOLATION: in EMERGENCY, Only emergency landing is allowed")
            return

        if event == "telemetry":
            if curr_record.state == DroneState.IN_FLIGHT:
                if status == "fail":
                    curr_record.telementry_count += 1
                    if curr_record.telementry_count >= 3:
                        curr_record.state = DroneState.EMERGENCY
                        print(f"TRIGGER EMERGENCY")
                elif status == "ok":
                    curr_record.telementry_count = 0
                    print(f"{drone_id} is OKAY")
                return 
            else:
                print(f"VIOLATION cannot send telemetry from {curr_record.state.name}")
        
        if event == "emergency_land":
            if curr_record.state == DroneState.EMERGENCY:
                curr_record.state = DroneState.GROUNDED
                curr_record.telementry_count = 0
                print(f"{drone_id} okay: emergency landed")
            else:
                print(f"VIOLATION: Not an emergency")
            return

        next_state = EVENTS_TO_STATES.get(event)
        expected_state = VALID_TRANSITIONS.get(curr_record.state)

        if expected_state != next_state:
            print(f"VIOLATION, The {drone_id} is currently in {curr_record.state.name}")
            return
        curr_record.state = next_state
        print(f"The {drone_id} is now updated to {next_state.name}")

DroneFM = DroneFleetMonitor()
for id, event, *other in events:
    if other:
        result = other[0]
    else:
        result = None
    DroneFM.process_event(id,event,result)





