KEYBOARD  = moonlander
KEYMAP    = custom
QMK_HOME ?= $(HOME)/qmk_firmware
KEYMAP_DIR = $(QMK_HOME)/keyboards/$(KEYBOARD)/keymaps/$(KEYMAP)

.PHONY: install compile flash clean

## Copy keymap files into the QMK tree
install:
	@if [ ! -d "$(QMK_HOME)" ]; then \
		echo "ERROR: QMK firmware not found at $(QMK_HOME)"; \
		echo "Run:  qmk setup zsa/qmk_firmware -b firmware24"; \
		exit 1; \
	fi
	mkdir -p $(KEYMAP_DIR)
	cp keymap.c config.h rules.mk $(KEYMAP_DIR)/
	@echo "Keymap installed to $(KEYMAP_DIR)"

## Compile firmware (produces a .bin in QMK_HOME)
compile: install
	cd $(QMK_HOME) && qmk compile -kb $(KEYBOARD) -km $(KEYMAP)

## Compile & flash (put Moonlander in bootloader first)
flash: install
	cd $(QMK_HOME) && qmk flash -kb $(KEYBOARD) -km $(KEYMAP)

## Remove keymap from QMK tree
clean:
	rm -rf $(KEYMAP_DIR)
	@echo "Cleaned $(KEYMAP_DIR)"
