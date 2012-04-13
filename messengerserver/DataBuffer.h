#pragma once
class CDataBuffer
{
public:
	enum { header_length = 4 };
	enum { max_body_length = 1024 };

	CDataBuffer(void);
	~CDataBuffer(void);

	const char* data() const
	{
		return m_buffer;
	}

	char* data()
	{
		return m_buffer;
	}

	size_t length() const
	{
		return header_length + m_body_length;
	}

	const char* body() const
	{
		return m_buffer + header_length;
	}

	char* body()
	{
		return m_buffer + header_length;
	}

	size_t body_length() const
	{
		return m_body_length;
	}

	void body_length(size_t length)
	{
		m_body_length = length;
		if (m_body_length > max_body_length)
			m_body_length = max_body_length;
	}

	bool decode_header()
	{
		int header = 0;
		memcpy(&header, m_buffer , header_length);
		m_body_length = header;
		if (m_body_length > max_body_length)
		{
			m_body_length = 0;
			return false;
		}
		return true;
	}

	void encode_header()
	{
		memcpy(m_buffer, &m_body_length, header_length);
	}

private:
	char m_buffer[1024];
	size_t m_body_length;
};

