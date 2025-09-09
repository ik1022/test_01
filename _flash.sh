#!/bin/sh

pyocd flash  -uremote:host.docker.internal:5555 .bin/mcu.hex

exit 0
