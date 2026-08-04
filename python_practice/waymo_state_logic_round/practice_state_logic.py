# THIS ROUND IS ABOUT KEEPING TRACK OF THE STATES AND ITS LOGIC AND ITS VIOLATION BASED ON THE RULES

# for example
# A door. It's either OPEN or CLOSED.

# Rules:
# You can only open a closed door
# You can only close an open door

# Events coming in:
    # Open
    # Open    ← illegal, already open!
    # Close
    # Close   ← illegal, already closed!
    # Open

# variation 1 - simple logic

# current_state = "CLOSED"
# events = ["open", "open", "close", "close"]

# for event in events:
#     if event == "open":
#         if current_state == "OPENED":
#             print(f"VIOLATION: Door is already opened")
#         else:
#             current_state = "OPENED"
#             print(f"Door is now opened")
#     elif event == "close":
#         if current_state == "CLOSED":
#             print(f"VIOLATION: Door is already closed")
#         else:
#             current_state = "CLOSED"
#             print(f"Door is now closed") 
    
# variation 2 - Adding more layers (multiple doors)

# from enum import ENUM

# class doors(Enum):
#     DOOR_A = 1,
#     DOOR_B = 2,
#     DOOR_C = 3

# doors = {}
# events = [
#     {"door_A", "open"},
#     {"door_A", "open"},
#     {"door_B", "close"},
#     {"door_B", "close"},
# ]

# for door_id, event in events:
#     if door_id not in doors:
#         doors[door_id] = "close"
#     curr_state = doors[door_id]
#     if event == "open":
#         if curr_state == "open":
#             print(f"VIOLATION: Door is alredy opened")
#         else:
#             doors[door_id] = "open"
#             print(f"Door is now opened")
#     elif event == "close":
#         if curr_state == "close":
#             print(f"VIOLATION: Door is already closed")
#         else:
#             doors[door_id] = "close"
#             print(f"door is now closed")


########################################################################################

#OFFLINE → BOOTING → READY
# OFFLINE -> BOOTING
# BOOTING -> READY

# sensors = {}

# events = [
#     ("sensor_A", "boot"),
#     ("sensor_A", "activate"),  # should reach READY
#     ("sensor_B", "activate"),  # violation - skipped boot
#     ("sensor_A", "boot"),
# ]

# for sensor_id, state in events:
#     if sensor_id not in sensors:
#         sensors[sensor_id] = "OFFLINE"
#     current_state = sensors[sensor_id]

#     if state == "boot":
#         if current_state != "OFFLINE":
#             print(f"VIOLATION: The sensor is not ready")
#         else:
#             sensors[sensor_id] = "BOOTING"
#             print(f"The sensor is now booting")
#     if state == "activate":
#         if current_state != "BOOTING":
#             print(f"VIOLATION: The sensor is not ready")
#         else:
#             sensors[sensor_id] = "READY"
#             print(f"The sensor is now ready")

# print(sensors)

##########################################################################################

# from enum import Enum, auto

# class SensorState(Enum):
#     OFFLINE = auto() # 1
#     BOOTING = auto() # 2
#     READY = auto() # 3

# EVENTS_TO_STATE = {
#     "boot": SensorState.BOOTING,
#     "activate": SensorState.READY,
# }

# VALID_TRANSITIONS = {
#     SensorState.OFFLINE: SensorState.BOOTING,
#     SensorState.BOOTING: SensorState.READY,
# }

# class SensorValidator:
#     def __init__(self):
#         self.sensor_states = {}
#     def process_event(self, sensor_id, event):
#         # need sensor -> curr state, next state, expected state
#         curr_state = self.sensor_states.get(sensor_id, SensorState.OFFLINE) 
#         next_state = EVENTS_TO_STATE[event]
#         expected_state = VALID_TRANSITIONS.get(curr_state)
#         # check if the curr state = expected state
#         # if valid update if not mark as invalid
#         if expected_state != next_state:
#             print(f"Invalid Transition {sensor_id}: "
#                   f"from curr state {curr_state.name} to next_state {next_state.name}")
#             return
#         # update the state
#         self.sensor_states[sensor_id] = next_state
#         print(
#             f"Valid Transition for {sensor_id} "
#             f"from {curr_state.name} to {next_state.name}"
#         )

# events = [
#     ("sensor_A", "boot"),
#     ("sensor_A", "activate"),  # should reach READY
#     ("sensor_B", "activate"),  # violation - skipped boot
#     ("sensor_A", "boot"),
# ]
# validator = SensorValidator()
# for sensor_id, event in events:
#     validator.process_event(sensor_id, event)



#####################################################################################

# PATTERN :
# 
# 1. CREATE THE STATE (SENSOR VEHICLE)
# 2. EVENTS TO STATE
# 3. VALID TRANSITIONS
# 4. Class Validator 
#       -> Process event (get your curr state, next state, expected state).
#       -> If the next state doesnt match the expected then mark it as invalid.













