FROM gcc:12.2.0

COPY socket_client.c /src/socket_client.c

WORKDIR /src

RUN gcc -o client socket_client.c

EXPOSE 8888

ENTRYPOINT [ "/src/client" ]

CMD []