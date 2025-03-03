def findData(r, c, N):
    layer = min(r, c, N-1-r, N-1-c)
    sn = 0
    n = N
    for i in range(1, layer+1):
        sn += 4*(N-1)
        N = N-2
    sn += 1
    print("Starting Number:", sn)
    
    # Find in which part of the layer the data is in
    if r == layer:
        # Add col offset (top row)
        return sn + (c - layer)
    if r == n-1-layer:
        # Add col offset (bottom row)
        return sn + N-1 + N-1 + (N-1)-(c-layer)
    if c == layer:
        # Add row offset (left col)
        return sn + N-1 + N-1 + N-1 + (N-1)-(r-layer)
    if c == n-1-layer:
        # Add row offset (right col)
        return sn + N-1 + r-layer
    
    return "Can't Find"

print("Data :", findData(1, 1, 4))
print("Data :", findData(2, 3, 5))
print("Data :", findData(2, 1, 5))