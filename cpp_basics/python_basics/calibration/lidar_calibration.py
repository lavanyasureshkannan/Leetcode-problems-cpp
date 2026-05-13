import numpy as np

def fit_plane_ransac(points, threshold=0.02, iterations=500):
    best_plane = None
    max_inliers = -1
    
    for _ in range(iterations):
        # 1. Randomly sample 3 points
        idx = np.random.choice(len(points), 3, replace=False)
        p1, p2, p3 = points[idx]
        
        # 2. Build Model: Calculate normal (a, b, c) and d
        v1, v2 = p2 - p1, p3 - p1
        normal = np.cross(v1, v2)
        
        norm_len = np.linalg.norm(normal)
        if norm_len < 1e-6: continue 
        
        normal /= norm_len
        a, b, c = normal
        d = -np.dot(normal, p1)
        
        # 3. Score & Update: Find best-fitting plane
        distances = np.abs(np.dot(points, normal) + d)
        inliers = distances < threshold
        num_inliers = np.sum(inliers)
        
        if num_inliers > max_inliers:
            max_inliers = num_inliers
            best_plane = (a, b, c, d)
            
    return best_plane

import numpy as np

def verify_calibration(points, expected_dist=5.0):
    # 1. Run RANSAC (Assuming the function from earlier is defined)
    # This returns normal (a, b, c), offset (d), and a boolean mask of inliers
    normal, d, inliers = fit_plane_ransac(points)
    
    # 2. MEASURED DISTANCE (Translation Check)
    # The perpendicular distance from LiDAR origin to the wall
    measured_dist = abs(d) 
    dist_error = measured_dist - expected_dist
    
    # 3. ANGULAR ERROR (Rotation Check)
    # If wall is directly in front, expected normal is [1, 0, 0]
    expected_normal = np.array([1, 0, 0])
    dot_product = np.clip(np.dot(normal, expected_normal), -1.0, 1.0)
    angular_error_deg = np.degrees(np.arccos(abs(dot_product)))
    
    # 4. PRECISION (Sensor Noise)
    # Root Mean Square Error of points belonging to the wall
    inlier_points = points[inliers]
    inlier_dist_to_plane = np.dot(inlier_points, normal) + d
    rmse = np.sqrt(np.mean(inlier_dist_to_plane**2))
    
    return {
        "dist_error_m": dist_error,      # Positive = overestimating distance
        "tilt_error_deg": angular_error_deg, # Alignment offset
        "sensor_precision_rmse": rmse,   # Average 'thickness' of the wall
        "inlier_ratio": np.sum(inliers) / len(points)
    }
