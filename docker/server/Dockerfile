FROM gcc:12.2.0

USER root

COPY socket_server /src/server

RUN chmod +x /src/server

WORKDIR /src

EXPOSE 8888

ENTRYPOINT [ "/src/server" ]

CMD []