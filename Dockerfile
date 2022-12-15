
FROM gcc:latest
WORKDIR /usr/src/Project
COPY Project.cpp .
RUN gcc -o Project Project.cpp -lstdc++
CMD ["./Project"]