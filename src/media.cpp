#include "objects/media.hpp"

#include <string>
#include <sstream>
#include <cstdint>
#include "boost/property_tree/ptree.hpp"
#include "boost/property_tree/json_parser.hpp"
#include "objects/sizes.hpp"

namespace tal {

Media::Media(const std::string& json) {
    boost::property_tree::ptree tree;
    std::istringstream ss(json);
    boost::property_tree::read_json(ss, tree);
    this->construct(tree);
}

Media::Media(const boost::property_tree::ptree& tree) {
    this->construct(tree);
}

Media::operator std::string() const {
    std::stringstream ss;
    ss << "display_url: " << display_url << "\nexpanded_url: " << expanded_url
       << "\nid: " << id << "\nid_str: " << id_str
       << "\nindices: " << indices[0] << ", " << indices[1]
       << "\nmedia_url: " << media_url
       << "\nmedia_url_https: " << media_url_https << "\nsizes: " << sizes
       << "\nsource_status_id: " << source_status_id
       << "\nsource_status_id_str: " << source_status_id_str
       << "\ntype: " << type << "\nurl: " << url;
    return ss.str();
}

void Media::construct(const boost::property_tree::ptree& tree) {
    display_url = tree.get<std::string>("display_url", "");
    expanded_url = tree.get<std::string>("expanded_url", "");
    id = tree.get<std::int64_t>("id", 0);
    id_str = tree.get<std::string>("id_str", "");
    auto indices_tree = tree.get_child("indices");
    int count{0};
    for (auto& pair : indices_tree) {
        indices[count++] = pair.second.get_value<int>(0);
    }
    media_url = tree.get<std::string>("media_url", "");
    media_url_https = tree.get<std::string>("media_url_https", "");
    sizes = Sizes{tree.get_child("sizes")};
    source_status_id = tree.get<std::int64_t>("source_status_id", 0);
    source_status_id_str = tree.get<std::string>("source_status_id_str", "");
    type = tree.get<std::string>("type", "");
    url = tree.get<std::string>("url", "");
}
}  // namespace tal