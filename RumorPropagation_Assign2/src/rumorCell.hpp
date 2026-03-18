struct rumorState {
    int state;
    rumorState() : state(0) {}
};

inline std::ostream& operator<<(std::ostream& os, const rumorState& x) {
    os << "<" << x.state << ">";
    return os;
}

inline bool operator!=(const rumorState& x, const rumorState& y) {
    return x.state != y.state;
}

inline void from_json(const nlohmann::json& j, rumorState& s) {
    j.at("state").get_to(s.state);
}
