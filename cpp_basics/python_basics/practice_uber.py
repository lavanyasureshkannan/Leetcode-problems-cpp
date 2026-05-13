def flag_vehicles(vehicle_errors: dict, 
                  threshold: float = 0.5) -> list:
    """
    vehicle_errors: {vehicle_id: reprojection_error}
    Returns list of vehicle_ids needing recalibration
    """
    # Edge case: empty input
    if not vehicle_errors:
        return []
    
    flagged = [
        vid for vid, error in vehicle_errors.items()
        if error > threshold
    ]
    
    return flagged

# Example
errors = {
    "V001": 0.3,
    "V002": 1.8,
    "V003": 0.4,
    "V004": 2.1
}
print(flag_vehicles(errors))
# Output: ["V002", "V004"]

def filter_quality_frames(frames: list, 
                          config: dict) -> list:
    """
    frames: list of dicts with sensor frame metadata
    config: quality thresholds per city
    Returns only frames suitable for calibration
    """
    if not frames:
        return []
    
    quality_frames = []
    
    for frame in frames:
        # Hard filters — reject immediately
        if frame.get('weather') != 'clear':
            continue
        if frame.get('vehicle_speed') > config.get('max_speed', 40):
            continue
        if frame.get('brightness') < config.get('min_brightness', 80):
            continue
        if frame.get('sensor_dropout', False):
            continue
            
        # Signal quality filter
        if frame.get('landmark_confidence', 0) < config.get('min_confidence', 0.9):
            continue
        if frame.get('num_landmarks', 0) < 3:
            continue
            
        quality_frames.append(frame)
    
    return quality_frames

# Example
config = {
    'max_speed': 40,
    'min_brightness': 80,
    'min_confidence': 0.9
}

frames = [
    {'weather': 'clear', 'vehicle_speed': 30, 
     'brightness': 90, 'sensor_dropout': False,
     'landmark_confidence': 0.95, 'num_landmarks': 5},
    
    {'weather': 'rain', 'vehicle_speed': 30,
     'brightness': 90, 'sensor_dropout': False,
     'landmark_confidence': 0.95, 'num_landmarks': 5},
     
    {'weather': 'clear', 'vehicle_speed': 60,
     'brightness': 90, 'sensor_dropout': False,
     'landmark_confidence': 0.95, 'num_landmarks': 5}
]

print(len(filter_quality_frames(frames, config)))
# Output: 1 (only first frame passes)

def detect_systematic_drift(vehicle_deltas: dict,
                            city: str,
                            threshold_pct: float = 0.70,
                            drift_tolerance: float = 0.5) -> dict:
    """
    vehicle_deltas: {vehicle_id: {'city': str, 'drift': float}}
    Positive drift = one direction, negative = other
    Returns: detection result with details
    """
    # Filter by city
    city_vehicles = {
        vid: data for vid, data in vehicle_deltas.items()
        if data['city'] == city
    }
    
    if not city_vehicles:
        return {'detected': False, 'reason': 'no data'}
    
    total = len(city_vehicles)
    
    # Count directional drift
    positive = sum(
        1 for data in city_vehicles.values()
        if data['drift'] > drift_tolerance
    )
    negative = sum(
        1 for data in city_vehicles.values()
        if data['drift'] < -drift_tolerance
    )
    
    # Check if majority drifting same direction
    if positive / total >= threshold_pct:
        return {
            'detected': True,
            'direction': 'positive',
            'affected_vehicles': positive,
            'total_vehicles': total,
            'percentage': round(positive / total * 100, 1)
        }
    
    if negative / total >= threshold_pct:
        return {
            'detected': True,
            'direction': 'negative', 
            'affected_vehicles': negative,
            'total_vehicles': total,
            'percentage': round(negative / total * 100, 1)
        }
    
    return {'detected': False, 'reason': 'no systematic drift'}

# Example
deltas = {
    'V001': {'city': 'Seattle', 'drift': 0.8},
    'V002': {'city': 'Seattle', 'drift': 0.9},
    'V003': {'city': 'Seattle', 'drift': 0.7},
    'V004': {'city': 'Seattle', 'drift': -0.2},
    'V005': {'city': 'Seattle', 'drift': 0.8},
}

print(detect_systematic_drift(deltas, 'Seattle'))
# Output: {'detected': True, 'direction': 'positive',
#           'affected_vehicles': 4, 'total_vehicles': 5,
#           'percentage': 80.0}


from abc import ABC, abstractmethod 

class shape:
    @abstractmethod
    def display(self):
        pass
    def __del__(self):
        print("Shape is getting destroyed")

class circle(shape):
    def display(self):
        print("Draw a circle")
class square(shape):
    def display(self):
        print("Draw a sqaure")
class shape_factory:
    shape_map = {
        "CIRCLE" : circle,
        "SQUARE" : square
    }

    @staticmethod
    def create_shape(name_of_shape: str) ->shape:
        shape_class = shape_factory.shape_map.get(name_of_shape.upper())
        if not shape_class:
            print("Not a valid shape")
        return shape_class()

if __name__ == "__main__":
    shape1 = shape_factory.create_shape("circle")
    shape1.display()



# Lists -> Lists are the containers that can hold any data type.
# They are muttables

fruits = ["bannana", "apple", 1, 2, [1,2,3]]
print(fruits)

# Tuples -> Tuples are immutable. They are of same data type
elements = (1,2,3)
print(elements)

# dictionaries -> They are like key and value pairs

person = {
    "name" : "lala",
    "age" : 26,
    "address": "california"
}
print(person)

# set -> returns unique values
numbers = {1,2,3,2,1} 
print(numbers)

# convert list to dictionary
a = [10,20,30]
b = {}
for index, value in enumerate(a):
    b[index] = value
# b = {index : value for index, value in enumerate(a)}
print(b)


keys = ["a","b","c"]
values = [1,2,3]

d = dict(zip(keys, values))
print(d)

# create a mask of even
a = [10,20,33,41,50]
mask = [x%2 == 0 for x in a]
print(mask)