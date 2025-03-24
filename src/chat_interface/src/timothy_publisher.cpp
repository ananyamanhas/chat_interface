#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class TimothyPublisher : public rclcpp::Node {
public:
    TimothyPublisher() : Node("timothy_publisher") {
        publisher_ = this->create_publisher<std_msgs::msg::String>("chat_topic", 10);
        timer_ = this->create_wall_timer(
            std::chrono::seconds(2), 
            std::bind(&TimothyPublisher::send_message, this)
        );
    }

private:
    void send_message() {
        auto message = std_msgs::msg::String();
        message.data = "Hello Bob, I need some colors!";
        RCLCPP_INFO(this->get_logger(), "Timothy: %s", message.data.c_str());
        publisher_->publish(message);
    }

    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TimothyPublisher>());
    rclcpp::shutdown();
    return 0;
}
