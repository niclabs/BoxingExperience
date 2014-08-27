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
	
	if (argc > 1) {
		printf("ERROR: This program shouldn't receive any argument\n");
		usage(argv[0]);
		exit(1);
	}
	
	char cwd[256];
  getcwd(cwd, 255);
	strcat(cwd, "/../vlc");
	
	char fname[34];
	char num[4];
	FILE *f;
	
	//SETTING SERVER CONFIGURATION
	f = fopen("lxc_conf/lxc-server.conf","w");
	fprintf(f, "lxc.network.type = veth\n"
			"lxc.network.name = eth0\n"
			"lxc.network.flags = up\n"
			"lxc.network.link = br-server\n"
//			"lxc.network.ipv4 = 10.10.0.2/24\n" // previous ip assignment
			"lxc.network.ipv4 = 10.100.2.2/24\n"
//			"lxc.network.ipv4.gateway = 10.10.0.1\n"
			"lxc.mount.entry = %s"
			" /var/lib/lxc/server/rootfs/home/jcarrera/Documents/vlc"
			" none bind 0 0\n"
			"lxc.mount.entry = /usr/lib"
			" /var/lib/lxc/server/rootfs/usr/lib"
			" none bind 0 0\n", cwd);
	fclose(f);

	//SETTING SLOWCLIENT CONFIGURATION
	strcpy(fname, "lxc_conf/lxc-client-");
	sprintf(num, "%s", "x");
	strcat(fname, num);
	strcat(fname, ".conf");
	f = fopen(fname,"w");
	fprintf(f, "lxc.network.type = veth\n"
			"lxc.network.name = eth0\n"
			"lxc.network.flags = up\n"
			"lxc.network.link = br-%s-c\n"
			"lxc.network.ipv4 = 10.%d.%d.2/24\n"
//				"lxc.network.ipv4.gateway = 10.%d.%d.1\n"
			"lxc.mount.entry = %s"
			" /var/lib/lxc/client-%s/rootfs/home/jcarrera/Documents/vlc"
			" none bind 0 0\n"
			"lxc.mount.entry = /usr/lib"
			" /var/lib/lxc/client-%s/rootfs/usr/lib"
			" none bind 0 0\n",
				"x",
//				30+i/256, i%256,
				100, 3,
//					30+i/256, i%256,
				cwd,
				"x", "x");
	fclose(f);

}

void usage(char *s) {
	printf("Usage: %s", s);
}
