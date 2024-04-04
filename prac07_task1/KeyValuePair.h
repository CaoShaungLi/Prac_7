#ifndef _KEY_VALUE_PAIR_H
#define _KEY_VALUE_PAIR_H

template<typename Key, typename Value>
class KeyValuePair
{
    private:
    Key m_key;
    Value m_value;

    public:
    KeyValuePair(const Key& key, const Value& value);
    const Key& getKey() const;
    void setKey(const Key& key);

    const Value& getValue() const;
    void setValue(const Value& value);
};

template <typename Key, typename Value>
KeyValuePair<Key,Value>::KeyValuePair(const Key& key, const Value& value)
{
    m_key = key;
    m_value = value;
}

template <typename Key, typename Value>
const Key&  KeyValuePair<Key, Value>::getKey() const
{
    return m_key;
}

template <typename Key, typename Value>
const Value&  KeyValuePair<Key, Value>::getValue() const
{
    return m_value;
}

template <typename Key, typename Value>
void KeyValuePair<Key, Value>::setKey(const Key& key)
{
    m_key = key;
}

template <typename Key, typename Value>
void KeyValuePair<Key, Value>::setValue(const Value& value)
{
    m_value = value;
}

#endif