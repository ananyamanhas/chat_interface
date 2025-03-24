#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class BobSubscriber : public rclcpp::Node {
public:
    BobSubscriber() : Node("bob_subscriber") {
        subscription_ = this->create_subscription<std_msgs::msg::String>(
            "chat_topic", 10,
            std::bind(&BobSubscriber::receive_message, this, std::placeholders::_1)
        );
    }

private:
    void receive_message(const std_msgs::msg::String::SharedPtr msg) {
        RCLCPP_INFO(this->get_logger(), "Bob received: '%s'", msg->data.c_str());
    }

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<BobSubscriber>());
    rclcpp::shutdown();
    return 0;
}
