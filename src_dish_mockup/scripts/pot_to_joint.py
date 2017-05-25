#!/usr/bin/env python
import roslib
roslib.load_manifest('src_dish_mockup')

import rospy
from std_msgs.msg import Float64

pub_1 = rospy.Publisher('pan_controller/command', Float64, queue_size=10)
pub_2 = rospy.Publisher('tilt_controller/command', Float64, queue_size=10)

def cb1(data):
    data.data = 0.75 * (2 * data.data / 1024.0 - 1) * 2 # 1024
    pub_1.publish(data)

def cb2(data):
    data.data = 0.75 * (2 * data.data / 1024.0 - 1) * 2 # 1024
    pub_2.publish(data)

# def pot_sub():
#     rospy.Subscriber('pot1_val', Float64, cb1)
#     rospy.Subscriber('pot2_val', Float64, cb2)
#     rospy.spin()

# def joint_pub():

if __name__ == '__main__':
    rospy.init_node('pot_to_joint')
    rospy.Subscriber('pot1_val', Float64, cb1)
    rospy.Subscriber('pot2_val', Float64, cb2)

    rate = rospy.Rate(10)
    while not rospy.is_shutdown():
        rospy.spin()
        rate.sleep()

    # pot_sub()

    # try:
    #     joint_pub()
    # except rospy.ROSInterruptException:
    #     pass
