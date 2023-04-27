FROM klee/klee:2.3

RUN sudo apt-key adv --keyserver keyserver.ubuntu.com --recv-keys 42D5A192B819C5DA
RUN sudo apt-get update
RUN sudo apt-get install -y \
    openssh-server \
    openssh-client

RUN sudo service ssh start
EXPOSE 22

ENTRYPOINT ["/bin/bash"]
