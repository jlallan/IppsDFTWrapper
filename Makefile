.PHONY: clean all

S = src
B = build
O = out
INC_DIR = include

CC = gcc
CFLAGS = -O3
IFLAGS = -I$(INC_DIR) -I${IPPROOT}/include
LFLAGS = -L${IPPROOT}/lib/intel64 -lm -lippcore -lippvm -lipps

OUT = $(O)/libippsdftwrapper.so

all: $(B) $(O) $(OUT)

$(OUT): $(B)/ippsdfttgf.o $(B)/ippsdfttgd.o $(B)/ippsdftcommon.o
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ -shared $^

$(B)/ippsdfttgf.o: $(S)/ippsdfttg.c
	$(CC) $(CFLAGS) -DDFT_SINGLE $(IFLAGS) -fPIC -c $< -o $@

$(B)/ippsdfttgd.o: $(S)/ippsdfttg.c
	$(CC) $(CFLAGS) $(IFLAGS) -fPIC -c $< -o $@

$(B)/ippsdftcommon.o: $(S)/ippsdftcommon.c
	$(CC) $(CFLAGS) $(IFLAGS) -fPIC -c $< -o $@

$(B):
	@mkdir -p $@

$(O):
	@mkdir -p $@
	@cp $(INC_DIR)/ippsdftwrapper.h $@

clean:
	@rm -rf $(B)

distclean: clean
	@rm -rf $(O)
