#Vehicle Telemetry Monitor
# You're receiving heartbeat signals from a fleet of vehicles. Each vehicle sends events as it operates.
# States:
    # IDLE → ACTIVE → IDLE → ...

# Rules:
# A vehicle must be IDLE before it can start
# A vehicle must be ACTIVE before it can stop
# A vehicle can only send data while AVCTIVE
# A vehicle that was never seen before starts as IDLE

events = [
    ("vehicle_A", "start"),
    ("vehicle_A", "data"),
    ("vehicle_A", "data"),
    ("vehicle_A", "start"),   # violation - already ACTIVE
    ("vehicle_A", "stop"),
    ("vehicle_A", "data"),    # violation - already IDLE
    ("vehicle_B", "data"),    # violation - never started
    ("vehicle_B", "start"),
    ("vehicle_B", "stop"),
    ("vehicle_B", "stop"),    # violation - already IDLE
]

from enum import Enum, auto
class VehicleState(Enum):
    IDLE = auto()
    ACTIVE = auto()

EVENTS_TO_STATE = {
    "start" : VehicleState.ACTIVE,
    "stop" : VehicleState.IDLE
}

VALID_TRANSITION = {
    VehicleState.IDLE : VehicleState.ACTIVE, # starts legal from IDLE
    VehicleState.ACTIVE : VehicleState.IDLE # starts legal from ACTIVE
}

class VehicleRecord:
    def __init__(self):
        self.state = VehicleState.IDLE

class TelementryMonitor:
    def __init__(self):
        self.Vehicles: dict[str, VehicleRecord] = {}

    def process_events(self, Vehicle_ID: str, event: str) -> None:
        # 1. Record if its a new vehicle
        if Vehicle_ID not in self.Vehicles:
            self.Vehicles[Vehicle_ID] = VehicleRecord()
        record = self.Vehicles[Vehicle_ID]

        # 2. Handle the data seperately
        if event == "data":
            if record.state != VehicleState.ACTIVE:
                print(f"VIOLATION: Cannot send data because the {Vehicle_ID} is not ACTIVE")
            else:
                print(f"OKAY, Data received")
            return

        # 3. for start/stop
        next_state = EVENTS_TO_STATE.get(event)
        expected_state = VALID_TRANSITION.get(record.state)

        # 4. Check the validity of next state
        if expected_state != next_state:
            print(f"VIOLATION: , {Vehicle_ID} is already {record.state.name}" )
            return
        
        # 5. update the state
        record.state = next_state
        print(f"{Vehicle_ID} okay: now {next_state.name}")

TM_1 = TelementryMonitor()

for vehicles, event in events:
    TM_1.process_events(vehicles, event)



        

