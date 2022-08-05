// Copyright 2022 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <gtest/gtest.h>

#include <fastdds/rtps/common/LocatorWithMask.hpp>
#include <fastrtps/utils/IPLocator.h>

#include <rtps/network/ExternalLocatorsProcessor.hpp>

using namespace eprosima::fastdds::rtps;
using namespace eprosima::fastrtps::rtps;

struct ExternalAddress
{
    ExternalAddress(
            const std::string& address,
            uint8_t mask,
            uint32_t user_port,
            uint32_t metatraffic_port)
    {
        user.kind = LOCATOR_KIND_UDPv4;
        user.port = user_port;
        user.mask(mask);
        IPLocator::setIPv4(user, address);

        metatraffic = user;
        metatraffic.port = metatraffic_port;
    }

    LocatorWithMask user;
    LocatorWithMask metatraffic;
};

struct BasicNodeConfig
{
    // User and metatraffic locators for externality 2
    ExternalAddress public_ip_locators;
    ExternalAddress machine_ip_locators;
    ExternalAddress container_ip_locators;
};

TEST(ExternalLocatorsProcessorTests, add_external_locators_participant)
{

}

int main(
        int argc,
        char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
