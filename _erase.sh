#!/bin/sh

pyocd erase -uremote:host.docker.internal:5555 --mass

exit 0
