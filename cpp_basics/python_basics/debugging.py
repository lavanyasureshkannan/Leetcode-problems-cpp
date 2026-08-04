def validate_calibration(errors: list):
    if not errors:
        return "no data"
    avg = sum(errors) / len(errors)
    
    if avg < 0.5:
        return "excellent"
    if avg < 1.0:
        return "good"
    if avg < 1.5:
        return "acceptable"
    else:
        return "needs recalibration"