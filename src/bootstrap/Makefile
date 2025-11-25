# generate vmlinux header
vmlinux.h:
        bpftool btf dump file /sys/kernel/btf/vmlinux fo>

# build bpf kernel object file
bootstrap.bpf.o: bootstrap.bpf.c vmlinux.h
        clang -g -O2 -target bpf -c $< -o $@

# generate skeleton
bootstrap.skel.h: bootstrap.bpf.o
        bpftool gen skeleton $< > $@

# build app
bootstrap: bootstrap.c bootstrap.skel.h
        clang -g $< -lbpf -lelf -lz -o $@

# clean generated files
clean:
        rm -f bootstrap.bpf.o bootstrap.skel.h