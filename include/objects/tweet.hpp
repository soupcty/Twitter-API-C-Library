#ifndef DETAIL_TWEET_HPP
#define DETAIL_TWEET_HPP

#include <string>
#include <vector>
#include <cstdint>
#include <memory>
#include <boost/property_tree/ptree_fwd.hpp>
#include "objects_template.hpp"
#include "objects/coordinates.hpp"
#include "objects/entities.hpp"
#include "objects/place.hpp"

namespace tal {
struct User_data;

struct Tweet_data {
    explicit operator std::string() const;

    std::vector<std::unique_ptr<detail::Objects_template<User_data>>> contributors;
    Coordinates coordinates;
    std::string created_at;
    std::int64_t current_user_retweet_id;     // current_user_retweet.id
    std::string current_user_retweet_id_str;  // current_user_retweet.id_str
    Entities entities;
    int favorite_count;
    bool favorited;
    std::string filter_level;
    std::int64_t id;
    std::string id_str;
    std::string in_reply_to_screen_name;
    std::int64_t in_reply_to_status_id;
    std::string in_reply_to_status_id_str;
    std::int64_t in_reply_to_user_id;
    std::string in_reply_to_user_id_str;
    std::string lang;
    Place place;
    bool possibly_sensitive;
    std::int64_t quoted_status_id;
    std::string quoted_status_id_str;
    std::unique_ptr<detail::Objects_template<Tweet_data>> quoted_status_ptr;
    std::vector<std::pair<std::string, std::string>> scopes;
    int retweet_count;
    bool retweeted;
    std::unique_ptr<detail::Objects_template<Tweet_data>> retweeted_status_ptr;
    std::string source;
    std::string text;
    bool truncated;
    std::unique_ptr<detail::Objects_template<User_data>> user_ptr;
    bool withheld_copyright;
    std::vector<std::string> withheld_in_countries;
    std::string withheld_scope;

   protected:
    void construct(const boost::property_tree::ptree& tree);
};

using Tweet = detail::Objects_template<Tweet_data>;

}  // namespace tal
#endif  // DETAIL_TWEET_HPP
