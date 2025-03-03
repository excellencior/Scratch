def convert(times, expected):
    for i, time in enumerate(times):
        hour, mins = time.split(':')
        totime = ''
        if hour < '13':
            if hour == '12':
                totime = f'{hour}:{mins} PM'
            elif hour == '00':
                totime = f'12:{mins} AM'
            else:
                totime = f'{hour}:{mins} AM'
        else:
            hour = int(hour) - 12
            hour = str(hour)
            totime = f'{hour}:{mins} PM'
        
        print("Given:", times[i], ", Converted:", totime, ", Expected:", expected[i])

def better_convert(times, expected):
    for i, time in enumerate(times):
        hour, mins = time.split(':')
        hour = int(hour)
        
        # Cases
        totime = None
        if hour == 0: # Midnight
            totime = f'12:{mins} AM'
        elif hour == 12: # Noon
            totime = f'12:{mins} PM'
        else:
            totime = f'{hour % 12}:{mins}'
            if hour < 12:
                totime += ' AM'
            else:
                totime += ' PM'
        
        print("Given:", times[i], ", Converted:", totime, ", Expected:", expected[i])
        
times = [
    "00:00", "00:30", "01:00", "03:15", "06:45",
    "12:00", "12:30", "14:00", "15:20", "18:05",
    "19:00", "20:45", "23:59"
]

expected = [
    "12:00 AM", "12:30 AM", "1:00 AM", "3:15 AM", "6:45 AM",
    "12:00 PM", "12:30 PM", "2:00 PM", "3:20 PM", "6:05 PM",
    "7:00 PM", "8:45 PM", "11:59 PM"
]

# convert(times, expected)
better_convert(times, expected)