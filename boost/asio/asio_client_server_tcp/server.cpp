#include <iostream>
#include <functional>
#include <boost/asio.hpp>

int main() 
{
    boost::asio::io_service io_service;
    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), 2000);//Server address
    boost::asio::ip::tcp::acceptor acceptor(io_service, endpoint);

    for(;;) {
        boost::asio::ip::tcp::socket socket(io_service);
        acceptor.accept(socket);

        std::size_t const _lenght = 1024; //Max lenght
        char msg[_lenght];

        std::function<void(boost::system::error_code const&, std::size_t)> 
             f = [&](boost::system::error_code const& ec, std::size_t bytes) {
                 boost::asio::async_write(socket, boost::asio::buffer(msg, bytes), 
                      [&](boost::system::error_code const& ec, std::size_t) {
                          auto buf = boost::asio::buffer(msg, _lenght);
                          socket.async_read_some(buf, f);
                      });
             };

        socket.async_read_some(boost::asio::buffer(msg, _lenght), f);
        io_service.run();
    }      
    return 0;
}
