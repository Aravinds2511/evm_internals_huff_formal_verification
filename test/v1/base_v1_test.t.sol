// SPDX-License-Identifier: GPL-3.0-only
pragma solidity 0.8.20;

import {Test} from "forge-std/Test.sol";
import {HorseStore} from "../../src/horsestorev1/horsestore.sol";
import {IHorseStore} from "../../src/horsestorev1/Ihorsestore.sol";

abstract contract BaseV1Test is Test {
    IHorseStore horseStore;
    
    function setUp() public virtual {
        horseStore = IHorseStore(address(new HorseStore()));
    }

    function testReadNumberOfHorses() public view {
        uint256 nuberOfHorses = horseStore.readNumberOfHorses();
        assertEq(nuberOfHorses, 0);
    }

    function testSetNumberOfHorses() public {
        uint256 horseStoreNumber = 10;
        horseStore.updateHorseNumber(horseStoreNumber);
        assertEq(horseStore.readNumberOfHorses(), horseStoreNumber);
    }

    function testSetNumberFuzz(uint256 storeNumber) public {
        horseStore.updateHorseNumber(storeNumber);
        assertEq(horseStore.readNumberOfHorses(), storeNumber);
    }
}