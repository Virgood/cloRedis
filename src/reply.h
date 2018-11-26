
#ifndef CLORIS_REDIS_REPLY_H_
#define CLORIS_REDIS_REPLY_H_

namespace cloris {

typedef std::shared_ptr<RedisReply> RedisReplyPtr;

class RedisReply {
public:
    RedisReply();
    RedisReply(redisReply* reply, bool reclaim, ERR_STATE state, const char* err_msg);
    ~RedisReply();
    void Update(redisReply* rep, bool reclaim, ERR_STATE state, const char* err_msg); 

    ERR_STATE err_state() const { return err_state_; }
    bool error() const; 
    bool ok() const;
    std::string toString() const;
    int32_t toInt32() const;
    int64_t toInt64() const;
    std::string err_str() const;
    int type() const;
    bool is_nil() const;
    bool is_string() const;
    bool is_int() const;
    bool is_array() const;
    size_t size() const;

    RedisReplyPtr operator[](size_t index);
private:
    void UpdateErrMsg(const char* err_msg); 
    char err_str_[REDIS_ERRSTR_LEN]; //
    redisReply* reply_;
    bool reclaim_;
    ERR_STATE err_state_;
};

} // namespace cloris

#endif // CLORIS_REDIS_REPLY_H_
