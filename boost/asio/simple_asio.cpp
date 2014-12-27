#include <iostream>
#include <iterator>
#include <boost/asio.hpp>

int main() {
    boost::asio::io_service io_service;
    boost::array<unsigned char, 200> array;
    boost::asio::ip::udp::endpoint remote_endpoint;

    boost::asio::ip::udp::socket socket(io_service, 
                                 boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4()), 53);

    std::size_t read = socket.receive_from(boost::asio::buffer(array),remote_endpoint);
 
    std::copy(array.begin(), array.begin() + read, std::ostream_interator<char>(std::cout, ""));
    
    return 0;
}
