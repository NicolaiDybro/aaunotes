

```python
parallel(
    logs = read_json("logs.json"),
    
    critical_errors = logs 
        | filter(column="type", operator="==", value="error")
        | filter(column="level", operator="==", value="critical"),
    
    major_operations = logs 
        | filter(column="type", operator="==", value="operation")
        | filter(column="importance", operator="==", value="major"),
    
    user_activity = logs 
        | filter(column="type", operator="==", value="activity")
        | filter(column="permission", operator="<=", value=2)
)
| join(critical_errors, major_operations)
| call_api(url="https://developer-api.com/logs", method="POST")
| write_json("user_activity.log", user_activity)

```


```python
import json

def read_log(file_path):
    with open(file_path, "r") as f:
        for line in f:
            yield json.loads(line)

def filter_critical_errors(logs):
    return (log for log in logs if log["type"] == "error" and log["level"] == "critical")

def filter_major_operations(logs):
    return (log for log in logs if log["type"] == "operation" and log["importance"] == "major")

def filter_user_activity(logs, permission_level):
    return (log for log in logs if log["type"] == "activity" and log["permission"] <= permission_level)

def send_to_api(logs):
    for log in logs:
        print(f"Sending to API: {log}")

def write_to_file(logs, file_name):
    with open(file_name, "w") as f:
        for log in logs:
            f.write(json.dumps(log) + "\n")

def process_logs():
    logs = read_log("logs.json")
    
    critical_errors = list(filter_critical_errors(logs))
    major_operations = list(filter_major_operations(logs))
    important_logs = critical_errors + major_operations
    
    send_to_api(important_logs)
    
    logs = read_log("logs.json")  # Reread logs for user activity
    user_logs = list(filter_user_activity(logs, permission_level=2))
    write_to_file(user_logs, "user_activity.log")

process_logs()

```



- python GIL
- 