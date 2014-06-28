#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * NOTE: Designed to work with lxc v0.7.5. Since version v0.8, the gateway can
 * be set through the configuration variable "lxc.network.ipv4.gateway".
 */

void usage(char *s);

int main(int argc, char *argv[]) {
	int i, ns, nf;
	
	if (argc < 2) {
		printf("ERROR: Missing number of fast and slow clients\n");
		usage(argv[0]);
		exit(1);
	}
	
	if (argc < 3) {
		printf("ERROR: Missing number of slow clients\n");
		usage(argv[0]);
		exit(1);
	}
	
	char cwd[256];
  getcwd(cwd, 255);
	strcat(cwd, "/vlc");
	
	nf = atoi (argv[1]);
	ns = atoi (argv[2]);
	
	char fname[34];
	char num[4];
	FILE *f;
	
	f = fopen("lxc_conf/lxc-buffer.conf","w");
	fprintf(f, "lxc.network.type = veth\n"
			"lxc.network.name = eth0\n"
			"lxc.network.flags = up\n"
			"lxc.network.link = br-buffer\n"
			"lxc.network.ipv4 = 10.10.0.2/24\n"
//			"lxc.network.ipv4.gateway = 10.10.0.1\n"
			"lxc.mount.entry = %s"
			" /var/lib/lxc/buffer/rootfs/home/jcarrera/Documents/vlc"
			" none bind 0 0\n"
			"lxc.mount.entry = /usr/lib"
			" /var/lib/lxc/buffer/rootfs/usr/lib"
			" none bind 0 0\n", cwd);
	fclose(f);
	
	for (i = 0; i < nf; i++) {
		strcpy(fname, "lxc_conf/lxc-fast-client-");
		sprintf(num, "%d", i);
		strcat(fname, num);
		strcat(fname, ".conf");
		f = fopen(fname,"w");
		fprintf(f, "lxc.network.type = veth\n"
				"lxc.network.name = eth0\n"
				"lxc.network.flags = up\n"
				"lxc.network.link = br-%d-fast-c\n"
				"lxc.network.ipv4 = 10.%d.%d.2/24\n"
//				"lxc.network.ipv4.gateway = 10.%d.%d.1\n"
				"lxc.mount.entry = %s"
				" /var/lib/lxc/fast-client-%d/rootfs/home/jcarrera/Documents/vlc"
				" none bind 0 0\n"
				"lxc.mount.entry = /usr/lib"
				" /var/lib/lxc/fast-client-%d/rootfs/usr/lib"
				" none bind 0 0\n",
					i,
//					20+i/256, i%256,
					20+i/256, i%256,
					cwd,
					i, i);
		fclose(f);
	}

	for (i = 0; i < ns; i++) {
		strcpy(fname, "lxc_conf/lxc-slow-client-");
		sprintf(num, "%d", i);
		strcat(fname, num);
		strcat(fname, ".conf");
		f = fopen(fname,"w");
		fprintf(f, "lxc.network.type = veth\n"
				"lxc.network.name = eth0\n"
				"lxc.network.flags = up\n"
				"lxc.network.link = br-%d-slow-c\n"
				"lxc.network.ipv4 = 10.%d.%d.2/24\n"
//				"lxc.network.ipv4.gateway = 10.%d.%d.1\n"
				"lxc.mount.entry = %s"
				" /var/lib/lxc/slow-client-%d/rootfs/home/jcarrera/Documents/vlc"
				" none bind 0 0\n"
				"lxc.mount.entry = /usr/lib"
				" /var/lib/lxc/slow-client-%d/rootfs/usr/lib"
				" none bind 0 0\n",
					i,
					30+i/256, i%256,
//					30+i/256, i%256,
					cwd,
					i, i);
		fclose(f);
	}
}

void usage(char *s) {
	printf("Usage: %s <number_of_fast_clients> <number_of_slow_clients>", s);
}
