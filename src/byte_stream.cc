#include "byte_stream.hh"
#include <iostream>

using namespace std;

ByteStream::ByteStream( uint64_t capacity ) : capacity_( capacity ), stream( capacity ) {}

bool Writer::is_closed() const
{
  // Your code here.
  return {};
}

void Writer::push( string data )
{
  for (char c : data) {
    if ((head  - tail + 1) == (int) capacity_) {
      std::cout << "Buffer full!" << std::endl;
      return;
    }
    stream[head] = (byte) c;
    head = (head + 1) % capacity_;
    total_bytes_pushed++;
  }
}

void Writer::close()
{
  // Your code here.
}

uint64_t Writer::available_capacity() const
{
  return capacity_ - (head - tail);
}

uint64_t Writer::bytes_pushed() const
{
  return total_bytes_pushed;
}

bool Reader::is_finished() const
{
  return (head == tail);
}

uint64_t Reader::bytes_popped() const
{
  return total_bytes_popped;
}

std::string_view Reader::peek() const {
  // Calculate contiguous bytes available starting at tail
  size_t readable = 0;
  if (head >= tail) {
    readable = head - tail + 1;
  }

  // Reinterpret std::byte* as const char*
  const char* start_ptr = reinterpret_cast<const char*>(&stream[tail]);

  return std::string_view(start_ptr, readable);
}

void Reader::pop( uint64_t len )
{
  for (int i = tail; i <=(int) len; i++) {
    if (head == tail) {
      return;
    }
    tail = (tail + 1) % capacity_;
    total_bytes_popped++;
  }
}

uint64_t Reader::bytes_buffered() const
{
  return head - tail;
}
