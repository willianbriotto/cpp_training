#include <iostream>
#include <boost/asio.hpp>
#include <functional>

int main() 
{
    boost::asio::io_service io_service;
    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), 2000);
    boost::asio::ip::tcp::acceptor acceptor(io_service, endpoint);
                      // boost::system::error_code
    std::function<void(const boost::system::error_code& error, std::size_t bytes)> f;

    for(;;) {
        boost::asio::ip::tcp::socket socket(io_service);
        acceptor.accept(socket);

        std::size_t _size = 1024;//Max of bytes
        char msg[_size];

        boost::asio::async_write(socket, boost::asio::buffer(msg, _size), f);
        socket.async_read_some(boost::asio::buffer(msg, _size), f);
        io_service.run();
    }
    return 0;    
}
