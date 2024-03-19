# Makefile wrapper for waf

all:
	./waf

# free free to change this part to suit your requirements
configure:
	./waf configure --enable-examples --enable-tests

build:
	./waf build

install:
	./waf install

clean:
	./waf clean

distclean:
	./waf distclean


# DS for 1795
config:
	@python testing_config.py
config_no_graphic:
	time python xml2csv/xml2csv.py -p xml2csv/test123.xml
	time python testing_config.py --no_graphic