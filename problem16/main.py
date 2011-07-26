#!/usr/bin/env python

print reduce(lambda acc, i: acc + int(i), str(2**1000), 0)
