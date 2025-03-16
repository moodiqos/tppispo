CC=g++
CFLAGS=-Wall -Wextra -std=c++17
TARGET=latin_square
DESTDIR=$(CURDIR)/debian/latin-square
BINDIR=$(DESTDIR)/usr/bin
REQUIRED_PKGS="g++ make debhelper"

all: check_deps $(TARGET) install

$(TARGET): latin_square.o
	$(CC) $(CFLAGS) -o $(TARGET) latin_square.o

latin_square.o: latin_square.cpp
	$(CC) $(CFLAGS) -c latin_square.cpp

clean:
	rm -f $(TARGET) *.o
	rm -rf $(DESTDIR)

install: $(TARGET)
	mkdir -p $(BINDIR)
	cp $(TARGET) $(BINDIR)/

check_deps:
	@missing_pkgs=""; \
	for pkg in $(REQUIRED_PKGS); do \
		dpkg -s $$pkg >/dev/null 2>&1 || missing_pkgs="$$missing_pkgs $$pkg"; \
	done; \
	if [ -n "$$missing_pkgs" ]; then \
		echo "Отсутствуют пакеты:$$missing_pkgs"; \
		echo "Хотите установить их? [y/N]"; \
		read ans; \
		if [ "$$ans" = "y" ] || [ "$$ans" = "Y" ]; then \
			sudo apt update && sudo apt install -y $$missing_pkgs; \
		else \
			echo "Не все зависимости установлены!"; \
			exit 1; \
		fi \
	fi
