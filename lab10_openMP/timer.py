#!/usr/bin/python3
import time, os

start = time.time()
os.system('curl localhost:8000/ > /dev/null 2>&1')
os.system('curl localhost:8000/ > /dev/null 2>&1')
os.system('curl localhost:8000/ > /dev/null 2>&1')
end = time.time()

print("Time spent to get response from three consecutive requests: \
{} seconds".format(round(end-start, 3)))