# def convert(time):
#     time, seg = time.split()
#     hour, mins = time.split(':')
#     hour = int(hour)
#     totime = None
#     if hour==12 and seg=='AM':
#         totime = f'00:{mins}'
#     else:
#         if hour!=12 and hour >= 1 and seg=='PM':
#             hour += 12
#         totime = f'0{hour}:{mins}' if hour<10 and seg=='AM' else f'{hour}:{mins}'
    
#     return totime

def convert(time):
    time_str, period = time.split()
    hour, minute = map(int, time_str.split(':'))

    if period == 'AM':
        hour = 0 if hour == 12 else hour
    else:
        hour = 12 if hour == 12 else hour + 12

    return f'{hour:02}:{minute:02}'


def runTestCases(test_cases):
    for times in test_cases:
        totime = convert(times[0])
        print(f'Converted: {totime}, Expected: {times[1]}')


test_cases = [
    # Morning times
    ("12:00 AM", "00:00"),  # Midnight
    ("01:00 AM", "01:00"),
    ("06:30 AM", "06:30"),
    ("11:59 AM", "11:59"),

    # Noon and afternoon times
    ("12:00 PM", "12:00"),  # Noon
    ("01:00 PM", "13:00"),
    ("03:45 PM", "15:45"),
    ("11:59 PM", "23:59"),

    # Edge cases
    ("12:01 AM", "00:01"),  # Just past midnight
    ("12:01 PM", "12:01"),  # Just past noon
    ("12:00 PM", "12:00"),  # Exactly noon
    ("12:00 AM", "00:00"),  # Exactly midnight

    # Leading zero edge cases
    ("01:05 AM", "01:05"),  # Leading zero in minutes
    ("01:05 PM", "13:05"),  # Afternoon with leading zero
]

runTestCases(test_cases)