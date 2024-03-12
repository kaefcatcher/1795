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

config:
	@python testing_config.py
config_no_graphic:
	@python testing_config.py --no_graphic