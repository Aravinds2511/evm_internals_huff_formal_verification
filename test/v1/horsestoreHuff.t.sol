// SPDX-License-Identifier: GPL-3.0-only
pragma solidity 0.8.20;

import {BaseV1Test, IHorseStore} from "./base_v1_test.t.sol";
import {HuffDeployer} from "foundry-huff/HuffDeployer.sol";

contract HorseStoreHuffTest is BaseV1Test {
    string public constant HORSE_STORE_HUFF_LOCATION = "horsestorev1/horsestore";
    function setUp() public override {
        horseStore = IHorseStore(HuffDeployer.config().deploy(HORSE_STORE_HUFF_LOCATION));
    }
}