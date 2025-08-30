#include "byte_stream.hh"

using namespace std;

ByteStream::ByteStream( uint64_t capacity ) : capacity_( capacity ) {}

bool Writer::is_closed() const
{
  return closed_;
}

void Writer::push( string data )
{
  if ( closed_ || error_ ) {
    set_error();
    return;
  }

  if ( data.length() > available_capacity() ) { 
    data = data.substr( 0, available_capacity() );   }
  std::copy( data.begin(), data.end(), std::back_inserter( buffer_ ) );
  bytes_written_ += data.size();
}

void Writer::close()
{
  closed_ = true;
}

uint64_t Writer::available_capacity() const
{
  uint64_t ava_capacity = capacity_ - buffer_.size();
  return ava_capacity;
}

uint64_t Writer::bytes_pushed() const
{
  return bytes_written_;
}

bool Reader::is_finished() const
{
  bool res = closed_ && buffer_.empty();
  return res;
}

uint64_t Reader::bytes_popped() const
{
  return bytes_read_;
}

string_view Reader::peek() const
{
  if ( !buffer_.empty() ) {
    return std::string_view( &buffer_.front(), 1 );
  }
  return std::string_view();
}

void Reader::pop( uint64_t len )
{
  if ( len > buffer_.size() ) {
    len = buffer_.size();
  }
  buffer_.erase( buffer_.begin(), buffer_.begin() + len );
  bytes_read_ += len;
}

uint64_t Reader::bytes_buffered() const
{
  return buffer_.size();
}
