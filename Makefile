all: run

run:
	cd problem${p} && make

create:
	cp -r _template problem${p}

clean:
	@find . -name '*.o' -delete
	@find . -name '*.swp' -delete
