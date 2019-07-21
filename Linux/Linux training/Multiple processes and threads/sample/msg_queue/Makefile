CMAKE=cmake

all:
	@mkdir -p build
	@cd build && $(CMAKE) ../
	@cd build && $(MAKE) -s all
	@echo ""
	@echo "*-----------------------------*"
	@echo "|         Make success        |"
	@echo "*-----------------------------*"
	@echo ""
clean:
	@rm -rf build