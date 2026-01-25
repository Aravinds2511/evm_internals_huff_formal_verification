// SPDX-License-Identifier: GPL-3.0-only
pragma solidity 0.8.20;

import {BaseV1Test, HorseStore} from "./base_v1_test.t.sol";
import {HuffDeployer} from "foundry-huff/HuffDeployer.sol";

contract HorseStoreHuffTest is BaseV1Test {
    string public constant horseStoreHuffLocation = "horsestorev1/horsestore";
    function setUp() public override {
        horseStore = HorseStore(HuffDeployer.config().deploy(horseStoreHuffLocation));
    }
}