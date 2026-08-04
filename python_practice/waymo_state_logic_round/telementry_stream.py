# States:
# OFFLINE → ONLINE → OFFLINE → ...
# Rules:

# A vehicle must be OFFLINE before it can connect
# A vehicle must be ONLINE before it can disconnect
# A vehicle can only send ping while ONLINE
# If a vehicle sends 3 consecutive pings with no data, flag it as UNRESPONSIVE

events = [
    ("vehicle_A", "connect"),
    ("vehicle_A", "ping"),
    ("vehicle_A", "ping"),
    ("vehicle_A", "ping"),       # 3rd consecutive ping - flag UNRESPONSIVE
    ("vehicle_A", "disconnect"),
    ("vehicle_B", "ping"),       # violation - never connected
    ("vehicle_B", "connect"),
    ("vehicle_B", "connect"),    # violation - already ONLINE
    ("vehicle_C", "disconnect"), # violation - never connected
]

from enum import Enum, auto

class VehicleStates(Enum):
    OFFLINE = auto()
    ONLINE = auto()

EVENTS_TO_STATES = {
    "connect" : VehicleStates.ONLINE,
    "disconnect": VehicleStates.OFFLINE
}

VALID_TRANSITIONS = {
    VehicleStates.ONLINE : VehicleStates.OFFLINE,
    VehicleStates.OFFLINE : VehicleStates.ONLINE
}

class VehicleRecord:
    def __init__(self):
        self.state = VehicleStates.OFFLINE
        self.consecutive_pings = 0

class TelementryStreams:

    def __init__(self):
        self.vehicles: dict[str, VehicleRecord] = {} # vehicleID : State
    def process_event(self, vehicle_id:str, event:str) -> None:
        # 1. if its a new vehicle
        if vehicle_id not in self.vehicles:
            self.vehicles[vehicle_id] = VehicleRecord()
        curr_record = self.vehicles[vehicle_id]

        # 2. Handle Ping
        if event == "ping":
            if curr_record.state != VehicleStates.ONLINE:
                print(f"{vehicle_id} VIOLATION: cannot ping while OFFLINE")
                return
            curr_record.consecutive_pings += 1
            if curr_record.consecutive_pings >= 3:
                print(f"Third consecutive ping : Flag Unresponsive")
            else:
                print(f"{vehicle_id} OK: ping received")
            return
        curr_record.consecutive_pings = 0

        # 3. check the states
        next_state = EVENTS_TO_STATES.get(event)
        expected_state = VALID_TRANSITIONS.get(curr_record.state)

        
        # 4. check for the validity of states
        if expected_state != next_state:
            print(f"VIOLATION: THe {vehicle_id} is already {curr_record.state.name}")
            return

        # 5. Update the state
        curr_record.state = next_state
        print(f"{vehicle_id} updated to {next_state.name}")

TS_1 = TelementryStreams()

for vehicles, event in events:
    TS_1.process_event(vehicles, event)

        
            
