#!/bin/sh

retval=0

# Get submodule contents
git submodule init

# check for yaml
perl -e "use YAML"
if [[ $? -ne 0 ]]; then
	echo "Perl YAML module not installed!"
	retval=1
fi

perl -e "use Device::SerialPort"
if [[ $? -ne 0 ]]; then
	echo "Perl Device::SerialPort module not installed!"
	retval=1
fi

exit $retval

