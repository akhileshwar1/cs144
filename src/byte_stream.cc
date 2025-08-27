#include "byte_stream.hh"

using namespace std;

ByteStream::ByteStream( uint64_t capacity ) : capacity_( capacity ), stream( capacity ) {}

bool Writer::is_closed() const
{
  // Your code here.
  return {};
}

void Writer::push( string data )
{
  if ((head  - tail + 1) == 5) {
    return;
  }
  stream[head] = data;
  head = (head + 1) % capacity;
  return;
}
    static constexpr std::size_t capacity_ = 1024; // example fixed size
void Writer::close()
{
  // Your code here.
}

uint64_t Writer::available_capacity() const
{
  return capacity - head;
}

uint64_t Writer::bytes_pushed() const
{
  // Your code here.
  return head + 1;
}

bool Reader::is_finished() const
{
  return (head == tail);
}

uint64_t Reader::bytes_popped() const
{
  // Your code here.
  return tail + 1;
}

string_view Reader::peek() const
{
  // Your code here.
  return stream[tail];
}

void Reader::pop( uint64_t len )
{
  if (head == tail) {
    return;
  }
  byte item = stream[tail];
  tail = (tail + 1) % capacity;
}

uint64_t Reader::bytes_buffered() const
{
  // Your code here.
  return head - tail;
}
