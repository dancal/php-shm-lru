<?php

/** @generate-class-entries */

class IPCBoostUnorderedMap
{

    public function __construct(string $name, int $size) {}

    public function get(string $key): string {}

    public function set(string $key, string $value): bool {}

    public function unset(string $key): bool {}

    public function clear(): bool {}

    public function getFreeMemory(): int {}

    public static function remove(string $key): bool {}

}
