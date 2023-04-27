sudo docker run \
    --name klee \
    -p 35022:22 \
    -v $(pwd)/demo:/home/klee/demo \
    -itd kawaii
