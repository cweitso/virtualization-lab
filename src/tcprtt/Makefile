# generate vmlinux header
vmlinux.h:
	bpftool btf dump file /sys/kernel/btf/vmlinux format c > vmlinux.h

# ==================== tcprtt (fentry) ====================
# build bpf kernel object file
tcprtt.bpf.o: tcprtt.bpf.c vmlinux.h tcprtt.h bpf_tracing_net.h
	clang-18 -g -O2 -target bpf -D__TARGET_ARCH_x86 -c $< -o $@

# generate skeleton
tcprtt.skel.h: tcprtt.bpf.o
	bpftool gen skeleton $< > $@

# build app
tcprtt: tcprtt.c tcprtt.skel.h tcprtt.h
	clang-18 -g $< -lbpf -lelf -lz -o $@

# ==================== tcprtt_tp (tracepoint) ====================
# build bpf kernel object file
tcprtt_tp.bpf.o: tcprtt_tp.bpf.c vmlinux.h tcprtt.h bpf_tracing_net.h
	clang-18 -g -O2 -target bpf -D__TARGET_ARCH_x86 -c $< -o $@

# generate skeleton
tcprtt_tp.skel.h: tcprtt_tp.bpf.o
	bpftool gen skeleton $< > $@

# build app
tcprtt_tp: tcprtt_tp.c tcprtt_tp.skel.h tcprtt.h
	clang-18 -g $< -lbpf -lelf -lz -o $@

# ==================== targets ====================
all: tcprtt tcprtt_tp

# clean
clean:
	rm -f tcprtt tcprtt.bpf.o tcprtt.skel.h
	rm -f tcprtt_tp tcprtt_tp.bpf.o tcprtt_tp.skel.h

.PHONY: all clean