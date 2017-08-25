-Usage
   Support different Java version on your machine, and choose corrent Java version
   when you need.

- Manual
  1. Install java source code and binary into target path.
  2. Utilize command, as follow:
	sudo update-alternatives --install /usr/bin/javap javap */install_path/bin/javap 300
	sudo update-alternatives --install /usr/bin/java java */install_path/bin/java 300
	sudo update-alternatives --install /usr/bin/jar jar */install_path/bin/jar 300
	sudo update-alternatives --install /usr/bin/javac javac */install_path/bin/javac 300
	sudo update-alternatives --install /usr/bin/javaws javaws */install_path/bin/javaws 300
	sudo update-alternatives --install /usr/bin/javadoc javadoc */install_path/bin/javadoc 300
  3. Choose specific java version. as follow:
	sudo update-alternatives --config java
	sudo update-alternatives --config javac
	sudo update-alternatives --config jar
	sudo update-alternatives --config javap
	sudo update-alternatives –-config javaws
	sudo update-alternatives –-config javadoc
