all: run

run:
	@cd problem$p && make && make run args="${args}"

create:
	cp -r _template problem$p
	cd problem$p && sed -i _ s/{{p}}/${p}/g Makefile

clean:
	@for dir in `ls -p | egrep -v "^_" | egrep "*/"`; do make -C $$dir clean; done
	@find . -name '*.swp' -delete
