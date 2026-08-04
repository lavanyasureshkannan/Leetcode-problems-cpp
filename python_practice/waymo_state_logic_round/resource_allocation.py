# Resource Allocation
#     You have shared hardware resources (think: a camera, a LiDAR, a GPU). 
#     Multiple users can request them.

# Rules:
# A resource must be requested before it can be granted
# A resource must be released before it can be requested again
# A resource can only be held by one user at a time

# REQUESTED -> GRANTED -> RELEASED
# events = [
#     ("lidar_1", "user_A", "request"),
#     ("lidar_1", "user_A", "grant"),
#     ("lidar_1", "user_B", "request"),  # violation - already held by user_A
#     ("lidar_1", "user_A", "release"),
#     ("lidar_1", "user_A", "grant"),    # violation - not requested first
#     ("camera_1", "user_B", "grant"),   # violation - never requested
# ]

from enum import Enum, auto

# class Resources(Enum):
#     CAMERA = auto()
#     LIDAR = auto()
#     GPU = auto()



class ResourcesState(Enum):
    AVAILABLE = auto()
    REQUESTED = auto()
    GRANTED = auto()
    RELEASED = auto()

EVENTS_TO_STATE = {
    "request" : ResourcesState.AVAILABLE,
    "grant" : ResourcesState.REQUESTED,
    "release": ResourcesState.GRANTED,
}

VALID_TRANSITIONS = {
    ResourcesState.AVAILABLE : ResourcesState.REQUESTED,
    ResourcesState.REQUESTED : ResourcesState.GRANTED,
    ResourcesState.GRANTED : ResourcesState.AVAILABLE,
}
VALID_TRANSITIONS = {
    ResourcesState.AVAILABLE : ResourcesState.REQUESTED,
    ResourcesState.REQUESTED : ResourcesState.GRANTED,
    ResourcesState.GRANTED : ResourcesState.AVAILABLE,
}

class ResourceRecord:
    def __init__(self):
        self.state = "AVAILABLE"
        self.curr_user = "None"

class ResourceTracker:
    def __init__(self):
        self.resource_states: dict[str, ResourceRecord] = {}

    def process_Event(self, Resource_id: str, user_name: str, event: str) -> None:
        if Resource_id not in ResourcesState:
            self.resource_states[Resource_id] = ResourceRecord()
        # get the curr state, next state, expected state
        curr_state = self.resource_states.get(Resource_id, ResourcesState.REQUESTED)
        next_state = EVENTS_TO_STATE[events]
        if not next_state:
            print(f"Error, UNKNOWN EVENT ' {events}'")
        expected_state = VALID_TRANSITIONS.get(curr_state)

        if self.resource_in_use and self.curr_user != user_name:
            print(f"The resource is in use and its locked by {self.curr_user}")
        if expected_state != next_state:
            print(f"Invalid Transition {Resource} from curr_state {curr_state.name} to next state {next_state.name}")
            return
        self.resource_states[Resource] = next_state
        print(f"Valid Transition of {Resource} from curr_state {curr_state.name} to next state {next_state.name}")

Tracker = ResourceTracker()
events = [
    ("lidar_1", "user_A", "request"),
    ("lidar_1", "user_A", "grant"),
    ("lidar_1", "user_B", "request"),  # violation - already held by user_A
    ("lidar_1", "user_A", "release"),
    ("lidar_1", "user_A", "grant"),    # violation - not requested first
    ("camera_1", "user_B", "grant"),   # violation - never requested
]
for resource, user, event in events:
    Tracker.process_Event(resource, user, event)






